k=int(input())
j=[]
for i in range(k):
    n=list(map(int,input().split()))
    x=n[0]%n[1]
    j.append(n[1]-x if x!=0 else x)
print('\n'.join(str(q) for q in j))