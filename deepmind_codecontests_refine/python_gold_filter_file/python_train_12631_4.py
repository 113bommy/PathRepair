def flag(n,m):
    used = []
    for i in range(n):
        lst = list(input())
        try:
            if (lst[0] == used[-1]):
                return 'NO'
        except:
            pass
        if (lst.count(lst[0])!=m):
            return "NO"
        used.append(lst[0])
    return "YES"
n,m=map(int,input().split())
print(flag(n,m))