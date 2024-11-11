from math import factorial
dp=[[-1 for i in range (101)] for j in range(101)] # array utilizado para el mamoization donde se guardan las soluciones previamente calculadas
def solve(length,digit,a):
    if dp[length][digit] is not -1:
        return dp[length][digit] # si la solución ya fue precalculada se devuelve de manera instantanea
    elif digit is 9:
        if length >= a[9]:
            return 1 # si al llegar al análisis del dígito 9 el espacio para ubicarlos 
                     # es menor que la cantidad mínima a ubicar tengo una combinación válida  
        else:
            return 0 # en caso contrario no puedo construir una combinación
    elif digit is 0:
        ans=0
        for i in range(a[0],length):
            partial = solve(length-i,1,a) # ubicando i ceros en la combinación comenzando 
                                    # en el mínimo que debo ubicar de ceros para obtener una posible combinación válida
            partial *= combinations(length-1, i) # se calculan cuantas combinaciones se pueden generar a partir de una distribución válida 
                                                # sin contar la primera posición (el cero no puede estar ubicado en la primera posición)
            ans += partial
        dp[length][digit] = ans #se guarda la respuesta calculada en su ubicación correspondiente en el array del memoization
        return ans
    else:
        ans = 0
        for i in range(a[digit],length+1):
            partial = solve(length-i,digit+1,a) # se determina si ubicando i veces el dígito se puede llegar a una combinación válida 
                                                # comenzando i en la cantidad mínima a ubicar
            partial *= combinations(length, i) # se calculan la cantidad de combinaciones posibles a partir de una distribución válida
            ans += partial
        dp[length][digit] = ans
        return ans

def combinations(n, k):
    return factorial(n)//(factorial(k)*factorial(n-k)) # fórmula de combinaciones

max_val = 1000000007
length = int(input())
a = input().rstrip().split(' ')

min_length = 0
for i in range(0, len(a)):
    a[i] = int(a[i])
    min_length += int(a[i])
ans=0
for i in range(min_length, length+1):
    ans += solve(i,0,a)
    ans %= max_val
print(ans)

