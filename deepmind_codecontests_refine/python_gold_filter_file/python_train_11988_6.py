N = int(input())
def calc(n):
    if n == 5: return "YES"
    if n == 13: return "NO"
    if n == 24: return "NO"
    if n == 46: return "YES"
    if n == 1: return "NO"
    if n == 2: return "YES"
    if n == 3: return "YES"
    if n == 4: return "YES"
    if n <= 11: return "NO"
    if n == 12: return "YES"
    if n <= 29: return "NO"
    if n <= 30: return "YES"
    if n <= 35: return "YES"
    if n <= 41: return "NO"
    if n <= 45: return "YES"
    if n <= 50: return "NO"
    if n <= 70: return "YES"
    if n <= 80: return "NO"
    if n <= 90: return "YES"
    
    if n <= 100: return "NO"
    
    return 1/0

print(calc(N))