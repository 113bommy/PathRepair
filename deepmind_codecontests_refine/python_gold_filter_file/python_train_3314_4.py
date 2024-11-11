n,k=map(int,input().split())
A=[int(i) for i in input().split()]
tab=[0 for i in range(n+1)]
for num in A:
    tab[num]+=1
tab.sort(reverse=True)
print(n-sum(tab[:k]))