n, m =  map(int,input().split())
l = list(input())
T = 1
for i in range(n-m):
	if l[0+i]==l[m+i] and l[0+i]!=".":
		T=5
	elif l[0+i] == l[m+i] and l[0+i]==".":
	    l[0+i] = "0"
	    l[m+i] = "1"
	    T=0
	    break
	elif l[0+i]=="." and l[m+i]=="0":
		l[0+i]="1"
		T=0
		break
	elif l[0+i]=="." and l[m+i]=="1":
		l[0+i]="0"
		T=0
		break
	elif l[m+i]=="." and l[0+i]=="0":
		l[m+i]="1"
		T=0
		break
	elif l[m+i]=="." and l[0+i]=="1":
		l[m+i] = "0"
		T=0
		break
	elif l[0+i]!=l[m+i]:
		T=0
		break


if T:
    print("No")
    exit()
    	


for i in range(n):
	if l[i] == ".":
		l[i]="0"
print("".join(l))



