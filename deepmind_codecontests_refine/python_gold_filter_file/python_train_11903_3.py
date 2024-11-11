n = int(input())
s = str(input())
c = s.count("1")
l = []
if n>c:
    print(0)
else:
    if n == 0:
        f = 0
        count = 0
        for i in range(len(s)):
            if s[i] == "1":
                l.append(i)
        if len(l) == 0:
            count+=(((len(s))*(len(s) + 1))//2)
        else:
            for i in range(len(l)):
                if i == len(l) - 1:
                    bb = len(s) - l[i] - 1
                    bb = (bb*(bb+1))//2
                    count+=bb
                zz = l[i]-f
                count+=(((zz)*(zz+1))//2)
                f = l[i] + 1
        print(count)
    else:
        f = 0
        count = 0
        for i in range(len(s)):
            if s[i] == "1":
                l.append(i)
        for i in range(c-n+1):
            count+=(l[i]-f+1)
            w = i+n
            if i == c-n:
                w = len(s) - l[-1] - 1
                count+=w
            else:
                w = (l[w] - l[w-1])-1
                count+=w
            if i!=0 and i!=c-n :
                
                zz = (l[i+n] - l[i+n-1] - 1)*(l[i] - l[i-1] - 1)
                count+=zz
            else:
                if c == n:
                    zz = l[i]*(len(s) - l[i+n-1] - 1)
                    count+=zz
                else:
                    if i == 0:
                        zz = (l[i+n] - l[i+n-1] - 1)*l[i]
                        count+=zz
                    else:
                        zz = (l[i] - l[i-1] - 1)*(len(s) - l[i+n-1] - 1)
                        count+=zz

            f = l[i] + 1
        print(count)
        
        
    
            
            
            
            
        
