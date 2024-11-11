for _ in [0]*int(input()):
    s=input()
    a='NA'
    if s[:2]==">'" and s[-1]=='~' and '#' in s:
        s=s[2:-1].split('#')
        a=[a,'A'][set(s[0])==set(s[1])=={'='} and len(set(s))==1]
    elif s[:2]=='>^' and s[-2:]=='~~':
        s=s[2:-2]
        a=['NA','B'][len(s)==2*s.count('Q=') and len(s)>0]
    print(a)