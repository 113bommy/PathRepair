import math
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    pow2=[0]*12
    for i in l:
        if int(math.log(i,2)) < 12:
            pow2[int(math.log(i,2))]+=1
    for i in range(len(pow2)-1):
        if pow2[i]>=2:
            pow2[i+1]+=(pow2[i]//2)
    #print(pow2)
    if pow2[-1]>=1:
        print('YES')
    else:
        print("NO")