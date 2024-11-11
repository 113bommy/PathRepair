n=int(input())
l=list(input())
w=[]
count=0
for i in range(n):
	if l[i]=="B" :
		w.append(i)
m=[]
for i in range(n+1):
	if i in w:
		count+=1
	if i not in w:
		m.append(count)
		count=0
s=m.count(0)
print(len(m)-s)
for i in range(len(m)):
	if m[i]>0:
		print(m[i],end=' ')