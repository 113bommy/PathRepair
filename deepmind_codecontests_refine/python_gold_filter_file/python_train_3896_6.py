[r1, c1, r2, c2] = [int(i) for i in input().split()]

rook = 2
if (r1 == r2) or (c1 == c2):
    rook = 1

bishop = 2
if ((r1 + c1) % 2) != ((r2 + c2) % 2):
    bishop = 0
elif abs(r2 - r1) == abs(c2 - c1):
    bishop = 1

king = max(abs(r2 - r1), abs(c2 - c1))

print(rook, bishop, king)
			 	 				   	 		 				  	 	