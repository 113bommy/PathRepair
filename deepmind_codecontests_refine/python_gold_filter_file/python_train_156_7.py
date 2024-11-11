n, k = map(int, input().split())
ids = list(map(int,input().split()))
#any given id is produced at m = 1+(1+2)+(1+2+3)...(1+2+3+k)
# = sum from 1 to k of (sum from 1 to n of n)
q = 1
while k > q :
    k -=q
    q+=1

print(ids[k-1])
