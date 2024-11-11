def ans():
    
        n, k = map(int, input().split())
        a = input()
        l = list(a)
        for i in range(k):
            if l[i]=='?':
                for j in range(i+k, n, k):
                    if l[j]!='?':
                        l[i] = l[j]
                        break
        # print(l)
        for i in range(k):
            if l[i]!='?':
                for j in range(i+k, n, k):
                    if l[j] == '?':
                        l[j] = l[i]
                    elif l[j]!=l[i]:
                        print("NO")
                        return
        # print(l)
        one = l[:k].count('1')
        zero = l[:k].count('0')
        if one <= k//2 and zero <=k//2:
            print("YES")
        else:
            print("NO")

def solve():
    for _ in range(int(input())):
        ans()

solve()