n,k,a,b=[int(i)for i in input().split()]
s=""
mx=0
mn=0
cmx=""
cmn=""
if(a>=b):
	mx=a
	mn=b
	cmx="G"
	cmn="B"
else:
	mx=b
	mn=a
	cmx="B"
	cmn="G"
if(mx/(mn+1)>k):
	s="NO"
else:
	if(k>=mx):
		s=cmx*mx+cmn*mn
	elif mx==1:
		s+=cmx*mx+cmn*mn
	else:
		#print(mx,mn,cmx,cmn)
		leftmin=mn%((mx-1)//k)
		#print(leftmin)
		for i in range((mx-1)//k):
			s+=cmx*k+cmn*(mn//((mx-1)//k))
			if leftmin>0:
				if leftmin>=k-(mn//((mx-1)//k)):
					leftmin-=k-(mn//((mx-1)//k))
					s+=cmn*(k-(mn//((mx-1)//k)))
				else:	
					s+=cmn*leftmin
					leftmin=0
		s+=cmx*(mx-((mx-1)//k)*k)+cmn*leftmin
print(s)
