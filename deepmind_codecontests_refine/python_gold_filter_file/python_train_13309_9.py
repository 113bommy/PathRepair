N = int(input())
a = list(map(int,input().split()))
S = [0]*N
S[0] = a[0]

for i in range(1,N):
    S[i] = S[i-1] + a[i]

count = [0]*N
num = [0]*2
for i in range(2):
    value = 0
    for j in range(N):
        if (S[j]+value)*((-1)**(i+j)) <= 0:
            num[i] += abs(S[j] + value - (-1)**(i+j))
            value += (-1)**(i+j) - (S[j]+value)
        #print(i,num,value)

#print(S)
print(min(num))