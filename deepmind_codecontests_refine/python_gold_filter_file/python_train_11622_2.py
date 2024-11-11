t = int(input())
li = []
for _ in range(t):
    li.append(input().replace('u','oo'))

for _ in range(t):
    while 'kh' in li[_]:
        #print(li[_])
        li[_] = li[_].replace('kh' , 'h')

#for _ in range(t):
 #   print(li[_])

dict = {}
for _ in range(t):
    dict[li[_]] = 1
#print(dict)
print(len(dict))
     
