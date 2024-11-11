n = int(input())
R =["zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
F = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

if n < 20:
    print(R[n])
else:
    if n % 10:
       print(F[n//10 - 2 ] + "-" + R[n%10])
    else:
        print(F[n//10 - 2])
