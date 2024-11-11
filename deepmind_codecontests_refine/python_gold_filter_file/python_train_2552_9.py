n=int(input())
nombres=[]
rec=0
tot=0
nbr=input()
nbr=nbr.split(" ")
for x in range(0,n):
 a=int(nbr[x])
 while a in nombres and a!=0:
  a-=1
 tot+=a
 nombres.append(a)
print(tot-rec)