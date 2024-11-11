a1,a2,a3,a4=map(int,input().split())
nums=input()
counter=0
num=list(nums)
for i in num:
    if int(i)==1:
        counter+=a1
    if int(i)==2:
        counter+=a2
    if int(i)==3:
        counter+=a3
    if int(i)==4:
        counter+=a4
print(counter)
