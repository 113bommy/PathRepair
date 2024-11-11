n=int(input())
arr=[]
tmp=input().split()
for i in tmp:
	arr.append(int(i))
min=1000000000
for i in range(n):
	s=0
	for j in range(n):
		s+=((abs(i-j)+i+j)*2*arr[j])	
	if(min>s):
		min=s
print(min)