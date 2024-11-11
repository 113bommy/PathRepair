import math
n = int(input())
f = math.factorial
fact_n = f(n)
fact_5 = f(5)
fact_6 = f(6)
fact_7 = f(7)
print(fact_n // fact_5 // f(n - 5) + fact_n // fact_6 // f(n - 6) + fact_n // fact_7 // f(n - 7))