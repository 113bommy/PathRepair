for _ in[0]*int(input()):a,b=map(int,input().split());b-=a;print(b
and 2-((b>0)&b|(b<0)&~b))