def diverse_garland(n,strng): 
    strng=list(strng)
    count=0
    for i in range(n-1):
        if strng[i]!=strng[i+1]:
            continue
        else:
            l=["R","G","B"]
            count+=1
            if i==n-2:
                l.remove(strng[i])
            else:  
                l.remove(strng[i])
                if strng[i+2] in l:
                    l.remove(strng[i+2])
            strng[i+1]=l[0]
            
            
    strng=''.join(strng)
    print(count)
    print(strng)
    

if __name__ == '__main__':
    n=int(input())
    strng=input()
    
diverse_garland(n,strng)