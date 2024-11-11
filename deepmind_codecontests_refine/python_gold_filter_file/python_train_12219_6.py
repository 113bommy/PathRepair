# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
s1,s2,s3=0,0,0
for i in range(n):
	if i%3==0:
		s1+=a[i]
	elif i%3==1:
		s2+=a[i]
	else:
		s3+=a[i]
a=max(s1,s2,s3)	
if a==s1:
	print('chest')
elif a==s2:
	print('biceps')
else:
	print('back')					
