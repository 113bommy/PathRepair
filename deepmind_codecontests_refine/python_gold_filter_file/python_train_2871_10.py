
number = int(input())
lis = list(map(int,input().split(' ')))


for i in range(0,number//2,2):
    lis[i],lis[number-i-1] = lis[number-i-1],lis[i]
print (*lis)