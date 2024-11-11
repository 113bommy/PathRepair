# n=int(input())
# s1=0
# s2=0
# s3=0
# for _ in range(n):
#     x,y,z=(map(int,input().split()))
#     s1=s1+x
#     s2=s2+y
#     s3=s3+z
#
# if s1==0 and s2==0 and s3==0:
#     print("YES")
# else:
#     print("NO")

# l=[]
# for i in range(5):
#     arr=list(map(int,input().split()))
#     l.append(arr)
# # print(l)
# x,y=3,3
# for i in range(1,6):
#     for j in range(1,6):
#         if l[i-1][j-1]==1:
#             print(abs(x-i)+abs(y-j))


# n,t=map(int,input().split())
# s=input()
#
# for i in range(t):
#
#
#     s=s.replace("BG",'GB')
#
#
# print(s)

# s=input()
# for i in range(len(s)):
#     s = s.replace("--", '2')
#     s = s.replace("-.", "1")
#     s=s.replace(".",'0')
#
#
#
# print(s)
# n=int(input())
# n = n + 1
# res = set(map(int, str(n)))
# # print(res)
#
# while len(res)!=4:
#     n=n+1
#     res = set(map(int, str(n)))
#     if len(res)==4:
#         break
#
# print(n)
#
# s=input()
#
#
# t=s[0].upper()+s[1:]
#
# print(t)
# def lucky(s):
#     c=0
#     for i in range(len(s)-1):
#         if s[i]==s[i+1]:
#             c+=1
#     return(c)
#
#
# n=int(input())
# s = input()
#
# print(lucky(s))
# def prime(n):
#     for i in range(2,n):
#         if n%i==0:
#             return False
#     return True
# def ans(n,m):
#
#     for i in range(n+1,m+1):
#
#         if (prime(i)==True) :
#             if i==m:
#                 return("YES")
#             else:
#                 return("NO")
#     return("NO")
# n,m=map(int,input().split())
# print(ans(n,m))
# s1=list(map(int,input().strip()))
# s2=list(map(int,input().strip()))
#
# s=""
# for i in range(len(s1)):
#     s=s+str(s1[i]^s2[i])
# print(s)
n=int(input())
if n%2!=0:
    print(-1)
else:
    for i in range(n,0,-1):
        print(i,end=" ")
