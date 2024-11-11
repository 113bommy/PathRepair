N=int(input())
S=list(map(int,input().split()))

i=1
count=0
while N>=i:
    if S[i-1]==i:
        count+=1
        i+=2
    else:
        i+=1
print(count)

    