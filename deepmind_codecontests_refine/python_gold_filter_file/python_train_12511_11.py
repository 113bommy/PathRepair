# n=int(input())
# l1=list(map(int,input().split()))
# l2=list(map(int,input().split()))
# x=l1.count(-1)
# y=l2.count(-1)
# s1,s2=0,0
# count=0
# for i in range(n):
#     if l1[i]!=-1:
#         s1+=l1[i]
#     if l2[i]!=-1:
#         s2+=l2[i]
        
# if (x==1 and y==1):
#     print("Infinite")

# elif(x==2 or y==2):
    
#     s=abs(s1-s2)
#     s1=list(range(s+1))
#     s2=list(range(s+1))
#     for j in range(s+1):
#         for k in range(j,s+1):
#             if s1[j]+s2[k]==s:

#                 count+=1
#     print(count)
            
    
    
# elif((x==1 and y==0) or (x==0 or y==1)):
#     print(1)
n,k=map(int,input().split())
a=1
b=-(2*n+3)
c=(n*n) + n -(2*k)
d=b**2-4*a*c
x1=(-b+(d**.5))/(2*a)
x2=(-b-(d**.5))/(2*a)
# print(x1,x2)
if(x1==int(x1) and x1<n ):
    print(int(x1))
if(x2==int(x2) and x2<n ):
    print(int(x2))



