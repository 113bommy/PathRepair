# a = str(raw_input())
# b = str(raw_input())
# c = len(a)
# d = len(b)

# f = 0

# if c > d:
#   e = c-d
#   f = str(b)+ ('0' * e)
    
# elif d > c:
#   e = d - c
#   f = str(a)+ ('0' * e)
    


# #int(a)
# #int(f)
# #print(type(a),type(f))
# if int(a) - int(f) > 0:
#   print(">")
# elif int(a) - int(f) < 0 :
#   print("<")

# elif int(a) - int(f) == 0 :
#   print("=")

# a = int(raw_input("enter an array size"))
# n = [i for i in range(1,a+1)]
# for i in range(1,a+1):
        
# n = [7,6,4,3,1,10,13]
#n = [7,1,5,3,6,4]

# def profit(n):
#         for index,value in enumerate(n):
#             try:
#                 if n[index] > n[index+1]:
#                     pass
#                 else:
#                     print("stock bought at %d!"%n[index])
#                     length = len(n[index:])-1
#                     max_profit = max(n[index:])
#                     if n[index] < max_profit:
#                         print("stock sold - max profit is -> %d"%(max_profit-n[index]))
#                         break

            

#             except IndexError:
#                  "end of list"



# print(profit(n))


#cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
#cost = [10, 15, 20]


# def stairs(n):
#     f_cost = [0]*len(cost)
#     f_cost[0]= cost[0]
#     f_cost[1]=cost[1]
#     for i in range(2,len(cost)):
#         f_cost[i]= min(f_cost[i-1],f_cost[i-2]) + cost[i]
#         print(f_cost)
#     return min(f_cost[-2],f_cost[-1])

# print(stairs(cost))



#### max subarray sum ###
# n = [-2,1,-3,4,-1,2,1,-5,4]
#n = [-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]

# def sub_arr(n):
#     l_max = n[0]
#     g_max = n[0]
#     for i in n[1:]:
#         l_max = max(i,l_max+i)
#         g_max = max(l_max,g_max)
        
#     return g_max

# print(sub_arr(n)) 

#import traceback,pdb

#nums = [4,1,1,4]

# def robRecursive(nums, i):
#     if i < 0: 

#         return 0 #No houses, return 0 as the profit

#     return max(nums[i] + robRecursive(nums, i - 2), robRecursive(nums, i - 1)) # max profit is house 1+3 or house 2

#     # return robRecursive(nums, len(nums)-1) # Return the profit gained at the last house

# print(robRecursive(nums,len(nums)-1))



### hackerearth ###

# greedy - water container

# n = input()
# a,b  = map(int,input().split())
# c = [int(x) for x in input().split()]   

# def fill(c):
#     remain = b 
#     count = 0 
#     for i in sorted(c):
#         if remain >= i:
#             remain = remain - i
#             count += 1
#     return count 

# print(fill(c))



### codeforces greedy questions ###

#s,n = map(int,input().split())
#c = [input().split() for x in range(n)]

#c=[[1,99],[100,0]]


# print(c)

# def dragon(c):
#     a = s
#     for i in c:
#         if int(i[0])<= a:
#             a = a + int(i[1])
#             print("YES")
#         else:
#             print("NO")

# print(dragon(c))

# n = input()
# a = [int(x) for x in input().split()]

# #print(a.count(3))

# def taxi(a):
#     a = a.count(1)
#     b = a.count(2)
#     c = a.count(3)
#     d = a.count(4)
#     count = 0





#1,2,4,3,3

#4,3,3,2,1





# limit = int(raw_input())
# x = raw_input("").split(" ")
# x.sort(reverse=True)
# x = [int(i)for i in x ]
# j = limit-1
# ans = 0
# i = 0

# j=4
# while i<=j:
#     ans+=1
#     four = 4-x[i]
#     while x[j]<=four and j>=i:
#         four-=x[j]
#         j-=1
#     i+=1
# print ans


# 4,3,3,2,1


# using namespace std;

# int main()
# {
#     int n;
#     cin>>n;
#     int count1=0;
#     int count2=0;
#     int count3=0;
#     int ans=0;
#     vector<int> v(n);
#     for(int i=0;i<n;i++)
#     {
#         cin>>v[i];
#         if(v[i]==4)
#         {
#             ans++;
#         }
#         else if(v[i]==3)
#         {
#             count3++;
#         }
#         else if(v[i]==2)
#         {
#             count2++;
#         }
#         else
#         {
#             count1++;
#         }
#     }
    # count1=count1-count3;    ans = 1 , count1 = -1
    # ans+=count3;             ans = 3 
    # ans+=count2/2;           ans = 3
    # if(count2%2!=0)
    # {
    #     ans+=1;
    #     count1=count1-2;
    # }
    # if(count1>0)
    # {
    #     ans=ans+count1;
    # }
#     cout<<ans;
#     return 0;

# #1,2,4,3,3
# 1 2 3 4 4 2 1 3 1

# count1 = 3
# count2 = 2
# count3 = 2
# count4 = 2

#n = [2,2,2,4,3,3]
#n=[1,2,4,3,3]
from math import floor,ceil

# a = int(input())
# n = [int(x) for x in input().split()]
# ans = 0
# count1=0
# count2=0
# count3=0
# for i in n:
#     if i == 4:
#         ans=ans+1
#     elif i == 3:
#         count3=count3+1
#     elif i == 2:
#         count2 = count2 + 1
#     elif i == 1:
#         count1 = count1 + 1

# count1 = count1 - count3
# ans = ans + count3
# #print(ans)
# ans = ans + floor(count2/2)
#     #print(ans)
# if count2%2 != 0:
#     ans = ans + 1
#     count1 = count1-2
# if count1>0:

#     ans = ans+ceil((count1/4))


# print(ans)



#### puzzles div (2A) ####

n,m = input().split()
n = int(n)
m = int(m)
l = [int(x) for x in input().split()]


best = 999
l = sorted(l)
#print(l)
for i in range(m-n+1):
    #print(i)
    best = min(best,l[i+n-1] - l[i])
    #print(best)
print(best)


#n = [int(x) for x in input().split()]


# def puzzle(l):
#     if i >=len(l):
#         return 0
#     else:
#         return min(l[i+n]-l[i],puzzle()



#2 10

#4 5 6 7 8 9 10 11 12 12


