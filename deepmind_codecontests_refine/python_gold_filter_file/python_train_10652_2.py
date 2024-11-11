n=int(input())
for i in range(n):
        s=input()
        s+="-"
        s="-"+s
        l=[]
        
        for i in s:
                l.append(ord(i))
               
        if 97 not in l:
                print("NO")
        else:
                i=l.index(97)
                j=i
                a=97
                count=1
                while j>=0 and i<len(l):
                        
                        if l[i+1]==a+1:
                                i+=1
                                a+=1
                                count+=1
                        elif l[j-1]==a+1:
                                j-=1
                                a+=1
                                count+=1
                        elif count==len(l)-2:
                                print("YES")
                                break        
                        else:
                                
                                print("NO")
                                break
                        
                                
                