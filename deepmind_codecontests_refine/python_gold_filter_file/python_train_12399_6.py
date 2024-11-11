n=int(input())

a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]

a=sorted(a,reverse=True)
b=sorted(b,reverse=True)

score1=0
score2=0
i=1
j=0
k=0
while(j<n and k<n):
    if(i%2==1 and a[j]>b[k]):
        score1+=a[j]
        j=j+1
    elif(i%2==1 and a[j]<=b[k]):
        k=k+1
    elif(i%2==0 and a[j]<b[k]):
        score2+=b[k]
        k=k+1
    elif(i%2==0 and a[j]>=b[k]):
        j=j+1
    i=i+1


if(i%2==1 and j<n):
    for i in range(j,n,2):
        score1+=a[i]
elif(i%2==0 and j<n):
    for i in range(j+1,n,2):
        score1+=a[i]
elif(i%2==0 and k<n):
    for i in range(k,n,2):
        score2+=b[i]
elif(i%2==1 and k<n):
    for i in range(k+1,n,2):
        score2+=b[i]
print(score1-score2)