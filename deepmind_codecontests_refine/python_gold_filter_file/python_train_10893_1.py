n=int(input())
counts={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0}
can_be_zeros={'a':True,'b':True,'c':True,'d':True,'e':True,'f':True,'g':True,'h':True,'i':True,'j':True}
for i in range(n):
	line=input()
	len_line=len(line)
	if len_line>=1:
		can_be_zeros[line[0]]=False
	for j in range(len_line):
		counts[line[j]]+=10**(len_line-j-1)

sorted_counts=sorted(counts,key=counts.get)[::-1]
for i in range(10):
	cur=sorted_counts[i]
	if counts[cur]>0 and can_be_zeros[cur]:
		counts[cur]=0
		break
result=0
factor=1
for i in range(10):
	cur=sorted_counts[i]
	if counts[cur]>0:
		result+=counts[cur]*factor
		factor+=1
print(result)