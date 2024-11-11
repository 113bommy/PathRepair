n,t,c=map(int,input().split())
l=input().split()
counter=0
i=0
len_of_q=0
while (i<n):
  if int(l[i])>t:
    len_of_q=0
    i+=1
    continue
  i+=1
  len_of_q+=1
  if len_of_q>=c:
    counter+=1
    #print(l[i-c:i])
print(counter)

  