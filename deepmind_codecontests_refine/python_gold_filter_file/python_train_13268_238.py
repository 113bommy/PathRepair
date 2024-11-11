n=int(input())
k=0
for i in range(n):
    num=input()
    num=num.split()
    num[0]=int(num[0])
    num[1] = int(num[1])
    if num[1]>=num[0]+2:
        k+=1
print(k)