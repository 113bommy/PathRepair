from sys import stdin
import re
def main():
    inp=stdin
    pasword=inp.readline().strip()
    minuscula=re.findall("[a-z]",pasword)
    mayuscula=re.findall("[A-Z]",pasword)
    numero=re.findall("[0-9]",pasword)
    if len(pasword)>=5:
        if len(minuscula)>=1:
            if len(mayuscula)>=1:
                if len(numero)>=1:
                    print("Correct")
                else:
                    print("Too weak")
            else:
                print("Too weak")
        else:
            print("Too weak")
    else:
        print("Too weak")
main()
