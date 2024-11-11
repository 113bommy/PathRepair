A,B,C,D,E,F = map(int,input().split())

ws = []
for a in range(0,F+1,100*A):
	for b in range(0,F-a+1,100*B):
		x = a + b
		if x <= F:
			ws.append(x)
			
ss = []
for c in range(0,F+1,C):
	for d in range(0,F-c+1,D):
		y = c + d
		if y <= F:
			ss.append(y)
				
ans = [0,100*A,0]
for w in ws:
	for s in ss:
		ws = w+s
		
		if not ws <= F:
			continue
		
		if ws == 0:
			continue
		
		e = s/ws*100
				
		if not e <= E/(100+E)*100:
			continue
		
		if ans[0] < e:
			ans = [e,ws,s]
				
print(ans[1],ans[2])