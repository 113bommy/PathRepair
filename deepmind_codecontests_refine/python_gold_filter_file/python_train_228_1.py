t = int(input())

for _ in range(t):
    n,m = map( int, input().split())
    s = list(input())
    p = [ int(x) for x in input().split() ]
    
    p = sorted(p)
    
    dict = { 'a':0 , 'b':0, 'c':0, 'd':0 ,'e':0 ,'f':0 ,'g':0 ,'h':0 ,'i':0 ,'j':0 ,'k':0 ,'l':0 ,'m':0 ,'n':0 ,'o':0 ,'p':0 ,'q':0 ,'r':0 ,'s':0 ,'t':0 ,'u':0 ,'v':0 ,'w':0 ,'x':0 ,'y':0 ,'z':0 }
    
    l= m
    
    for a in s[:p[0]]:
        dict[a] += l+1
    
    for i in range(1,l):
        
        for a in s[p[i-1]:p[i]]:
            #print(a)
            dict[a] += l-i +1
     
    for a in s[p[l-1]:]:
        dict[a] +=1
    
    for v in dict.values():
        print(v, end = ' ')