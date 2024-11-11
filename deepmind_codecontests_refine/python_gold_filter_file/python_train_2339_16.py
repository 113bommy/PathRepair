import sys
F = sys.stdin.readline().strip()
M = sys.stdin.readline().strip()
S = sys.stdin.readline().strip()

for i in range (0, 3):
    x = ["rock", "paper", "scissors"]
    if F == x[i]:
        F = i      
    if M == x[i]:
        M = i      
    if S == x[i]:
        S = i      
if (F+M+S) % 3 != 1:
    print("?")
else:
    if (F - M + 3) % 3 == 1:
        print("F")
    if (M - S + 3) % 3 == 1:
        print("M")
    if (S - F + 3) % 3 == 1:
        print("S")