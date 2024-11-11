for i in range(int(input())):
    a=input()
    p=1
    temp=[]
    for i in a:
        temp.append(i)
    temp.sort()
    a=temp
    for i in range(len(a)-1):
	    if a[i]!='z':
		    if ord(a[i+1])==ord(a[i])+1:
			    p=1
		    else:
			    p=0
			    break
	    else:
		    if ord(a[i+1])==ord('a'):
			    p=1
		    else:
			    p=0
			    break
    if p==1:
	    print('yes')
    else:
        print('no')
