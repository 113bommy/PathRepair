# import sys
# # sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
# x=int(input())
# S=[0,0,0]
# L=list(map(int,input().split()))
# for i in range(x):
# 	if i%3==0:
# 		S[0]+=L[i]
# 	if i%3==1:
# 		S[1]+=L[i]
# 	if i%3==2:
# 		S[2]+=L[i]
# index=S.index(max(S))
# if index==0:
# 	print("chest")
# if index==1:
# 	print("biceps")
# if index==2:
# 	print("back")
count=0
n,k=map(int,input().split())
L=list(map(str,input().split()))
for i in range(n):
	if L[i].count('4')+L[i].count('7')<=k:
		count+=1
print(count)