h1=input().split(":")
h2=input().split(":")
for i in range(len(h1)):
  h1[i]=int(h1[i])
for i in range(len(h2)):
  h2[i]=int(h2[i])
  
def time(n, m):
  temp=((n-m)/2)+m
  if str(temp)[-1]!='0':
    other=int(str(temp)[-1])*6
    return [int(temp),int(other)]

  return [int(temp),0]

def time2(n, m):
  return int(((n-m)/2)+m)

decimals=time2(max(h1[-1],h2[-1]), min(h1[-1],h2[-1]))
hours=time(max(h1[0],h2[0]), min(h1[0],h2[0]))
hours[-1]=hours[-1]+decimals

if hours[-1]>=60:
  hours[0]+=1
  hours[-1]-=60
  
hours=str(hours).replace(',', ':').replace('[', '').replace(']','').replace(' ', '')
if ':' in hours[0:2]:
  hours='0'+hours
if ':' in hours[-2]:
  hours=hours[0:len(hours)-1]+"0"+hours[-1]
print(hours)