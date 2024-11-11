
def solve(n):
    if n % 2 == 0:
        return "Mahmoud"
    return "Ehab"

def driver():
    n = int(input())
    print(solve(n))

driver()