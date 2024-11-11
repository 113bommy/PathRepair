#t=list((input()))
#lst=['H','Q','9','+']
#if t[0] in lst:
#	if t[0]=='+':
#		print("NO")
#	else: print("YES")
#else: print("NO")


#Translation
#s1=input()
#s2=input()
#if s1==s2[::-1]:
#	print("YES")
#else: print("NO")


#Expression
#a,b,c=int(input()),int(input()),int(input())
#print(max(a+b*c,a*(b+c),a*b*c,(a+b)*c,a+b+c))


#Magnets
n=int(input())
lst=[]
for i in range(n):
	lst.append(input())
lst="".join(lst)
cnt=0
for i in range(len(lst)-1):
	if lst[i]==lst[i+1]:
		cnt+=1
if cnt==0:
	print(1)
else : print(cnt+1)