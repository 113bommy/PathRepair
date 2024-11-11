# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
s=input()
l=list(str(x) for x in range(1,10,2))
r=['a','e','i','o','u']
count=0
for x in s:
	if x in l or x in r:
		count+=1
print(count)