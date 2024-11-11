for _ in range(int(input())):
    s=input()
    n=len(s)
    if n>=3:
        if '1' in s and s.count('1')>1:
            k=s[::-1]
            i=s.index('1')
            j=n-(k.index('1')+1)
            z=s[i:j+1]
            if '0' in z:
                print(z.count('0'))
            else:
                print(0)
        else:
            print(0)
    else:
        print(0)
                
