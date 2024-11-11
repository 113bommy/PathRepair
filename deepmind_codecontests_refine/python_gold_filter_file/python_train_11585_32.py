for _ in[0]*int(input()):a,b=map(int,input().split());b-=a;print(b
and((b<0)&b|(b>0)&~b)+1)