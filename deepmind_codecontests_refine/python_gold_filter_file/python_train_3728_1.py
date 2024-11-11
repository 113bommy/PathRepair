x , y ,z , k = map(int, input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))

a.sort(reverse=True)
b.sort(reverse=True)
c.sort(reverse=True)

e = [i + j for i in a[:k] for j in b[:k]]
e.sort(reverse=True)
e = e[:k]
ans = [i + j for i in e for j in c[:k]]
ans.sort(reverse=True)

for i in range(k):
    print(ans[i])
