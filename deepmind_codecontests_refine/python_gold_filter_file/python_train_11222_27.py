
n=int(input())
h=list(map(int,input().split()))

score = [0]*n
for i in range(n-2,-1,-1):
    if h[i] >= h[i+1]:
        score[i] = score[i+1] + 1
 
print(max(score))