def solution(a,b):
    vowels="aeiouy"
    i=0
    c_out=""
    warned=0
    i=0
    while i<len(b):

        if not warned:
            if b[i] in vowels:
                warned=1
            c_out+=b[i]
        if warned:
            if b[i] in vowels:
                pass
            else:
                warned=0
                c_out+=b[i]
        
        i+=1

    return c_out
def answer():
    a = int(input())
    b = list(input())
    print(solution(a,b))
answer()