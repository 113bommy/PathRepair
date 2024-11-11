import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    s = list(input())
    o_lst = []
    for i in range(n):
        if s[i] == "1":
            o_lst.append(i)
    if not o_lst:
        print((n+k)//(k+1))
    else:
        cnt = 0
        o_lst.insert(0, -int(1e10))
        o_lst.append(int(1e10))
        for i in range(n):
            if s[i] == "0":
                l = 0
                r = len(o_lst)-1
                while r - l != 1:
                    m = (l+r) // 2
                    if o_lst[m] < i:
                        l = m
                    else:
                        r = m
                if i-o_lst[l] > k and o_lst[r]-i > k:
                    cnt += 1
                    o_lst[l] = i
        print(cnt)


