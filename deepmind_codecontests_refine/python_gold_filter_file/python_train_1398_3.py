rook = input()
knight = input()
rook = list(rook)
knight = list(knight)
rook[0] = ord(rook[0])-96
knight[0] = ord(knight[0])-96
s = set()
s.add((int(rook[0]),int(rook[1])))
s.add((int(knight[0]),int(knight[1])))
# print(s)
for i in range(1,9):
	s.add((int(rook[0]),i))
for i in range(1,9):
	s.add((i,int(rook[1])))
knight[1] = int(knight[1])
rook[1] = int(rook[1])
# print(s)
if knight[0]-1 > 0 and knight[1]-2 > 0:
	s.add((knight[0]-1,knight[1]-2))
if knight[0]-1 > 0 and knight[1]+2 <= 8:
	s.add((knight[0]-1,knight[1]+2))
if knight[0]+1 <= 8 and knight[1]-2 > 0:
	s.add((knight[0]+1,knight[1]-2))
if knight[0]+1 <= 8 and knight[1]+2 <= 8:
	s.add((knight[0]+1,knight[1]+2))
if knight[0]+2 <= 8 and knight[1]-1 > 0:
	s.add((knight[0]+2,knight[1]-1))
if knight[0]+2 <= 8 and knight[1]+1 <= 8:
	s.add((knight[0]+2,knight[1]+1))
if knight[0]-2 > 0 and knight[1]+1 <= 8:
	s.add((knight[0]-2,knight[1]+1))
if knight[0]-2 > 0 and knight[1]-1 > 0:
	s.add((knight[0]-2,knight[1]-1))
if rook[0]-1 > 0 and rook[1]-2 > 0:
	s.add((rook[0]-1,rook[1]-2))
if rook[0]-1 > 0 and rook[1]+2 <= 8:
	s.add((rook[0]-1,rook[1]+2))
if rook[0]+1 <= 8 and rook[1]+2 <= 8:
	s.add((rook[0]+1,rook[1]+2))
if rook[0]+1 <= 8 and rook[1]-2 > 0:
	s.add((rook[0]+1,rook[1]-2))
if rook[0]-2 > 0 and rook[1]+1 <= 8:
	s.add((rook[0]-2,rook[1]+1))
if rook[0]-2 > 0 and rook[1]-1 > 0:
	s.add((rook[0]-2,rook[1]-1))
if rook[0]+2 <= 8 and rook[1]+1 <= 8:
	s.add((rook[0]+2,rook[1]+1))
if rook[0]+2 <= 8 and rook[1]-1 > 0:
	s.add((rook[0]+2,rook[1]-1))
print(64-len(s))
