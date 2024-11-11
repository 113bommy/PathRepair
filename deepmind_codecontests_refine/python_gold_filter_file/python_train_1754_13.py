import sys

def diff(N,A,B,C,D):
    mini = (B+(N-1)*D-A)/(C+D)
    for i in range(int(mini), N-1):
        lower_bound = A + i*C - (N-i-1)*D
        upper_bound = A + i*D - (N-i-1)*C
        #print(lower_bound, upper_bound)
        if lower_bound <= B and B <= upper_bound:
            return True
        elif B < lower_bound:
            return False

str = sys.stdin.readline().strip() #"491995 412925347 825318103 59999126 59999339"
N,A,B,C,D = map(int,str.strip().split(" "))
print("YES" if diff(N,A,B,C,D) else "NO")