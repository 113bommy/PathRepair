a,v,b,w,t=map(int,open(0).read().split())
print(['NO','YES'][abs(b-a)<=(v-w)*t])