seq=list(input())
if len(seq)%2==1:
    print('No')
else:
    a=0;b=0
    for i in range (len(seq)//2):
        if seq[2*i]=='+':
            a+=1
        elif seq[2*i]=='-':
            b+=1
        if seq[2*i+1]=='+':
            b+=1
        elif seq[2*i+1]=='-':
            a+=1
    #print(a,b)
    if a==b:
        print('Yes')
    else:
        print('No')
