n=int(input())
A=list(map(int,input().split()))

i=0
day=0
MAX=A[0]
while i<n:
    #print(i+1,day,MAX)

    if i==MAX-1:
        day+=1
        i+=1
        if i<n:
            MAX=A[i]
    else:
        i+=1
        if i<n:
            MAX=max(MAX,A[i])

print(day)
    
