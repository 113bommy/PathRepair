input()
A=[0]+input().split()
H=len(A)
for i in range(1,H):
 print(f'node {i}: key = {A[i]}, {f"parent key = {A[i//2]}, "if i>1 else""}{f"left key = {A[2*i]}, "if 2*i<H else""}{f"right key = {A[2*i+1]}, "if 2*i+1<H else""}')
