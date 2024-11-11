n,s,m,min,max,h1=int(input()),input(),input(),0,0,[0]*10
h2=[]+h1
for i in m:h1[int(i)]+=1
for i in s:h2[int(i)]+=1
p,q=[]+h1,[]+h2
for i in range(10):
                while q[i]:
                                for j in range(i,10):
                                                if p[j]:
                                                                p[j]-=1
                                                                break
                                else:
                                                min+=1
                                                for x in p:
                                                                if x:
                                                                                x-=1
                                                                                break
                                q[i]-=1
for i in range(10):
                while h2[i]:
                                for j in range(i+1,10):
                                                if h1[j]:
                                                                max+=1
                                                                h1[j]-=1
                                                                break
                                h2[i]-=1
print (min,max,sep="\n")
