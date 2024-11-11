p=lambda x:print(f'{x//3600:02}:{x//60%60:02}:{x%60:02}')
for e in iter(input,'-1 -1 -1'):
 h,m,s=map(int,e.split())
 d=7200-h*3600-m*60-s
 p(d);p(d*3)
