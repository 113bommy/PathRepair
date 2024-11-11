#coding:utf-8
n=int(input())
for i in range(n):
    str_=input()
    #print(str_)
    str_=str_.split(' ')
    a=int(str_[0])
    b=int(str_[1])
    for j in range(a):
        tmp=j%b
        ans=chr(ord('a')+tmp)
        print(ans,end="")
    print()