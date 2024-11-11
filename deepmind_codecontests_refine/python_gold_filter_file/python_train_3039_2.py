t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    s = input()
    j = 0
    ans = []
    while j < n:
        if s[j] == '(':
            q = j + 1
            while s[q] != ')':
                q += 1
            first, second = j + 2, q + 1
            if first > second:
                first, second = second, first            
            if q + 1 >= n:
                p = ''
            else:
                p = s[q + 1:]        
            b = s[j + 1:q + 1]
            s = s[:j + 1] + b[::-1] + p
            j += 2
        else:
            q = j + 1
            while s[q] != '(':
                q += 1
            first, second = j + 1, q + 1
            if first > second:
                first, second = second, first
            if q + 1 >= n:
                p = ''
            else:
                p = s[q + 1:]
            a = s[:j]
            b = s[j:q + 1]
            s = s[:j] + b[::-1] + p
        if first != second:
            ans.append([first, second])
    if k * 2 != n:
        ans.append([2 * k, n - 1])    
    print(len(ans))
    for i in ans:
        print(i[0], i[1])   