ones = ('zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine')

twos = ('ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen')

tens = ('twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety', 'hundred')

suffixes = ('', 'Thousand', 'Million', 'Billion')

def process(number, index):
    
    if number=='0':
        return 'zero'
    
    length = len(number)
    
    if(length > 3):
        return False
    
    number = number.zfill(3)
    words = ''
 
    hdigit = int(number[0])
    tdigit = int(number[1])
    odigit = int(number[2])
    
    words += '' if number[0] == '0' else ones[hdigit]
    words += ' Hundred ' if not words == '' else ''
    
    if(tdigit > 1):
        words += tens[tdigit - 2]
        words += '-'
        words += ones[odigit]
    
    elif(tdigit == 1):
        words += twos[(int(tdigit + odigit) % 10) - 1]
        
    elif(tdigit == 0):
        words += ones[odigit]

    if(words.endswith('Zero')):
        words = words[:-len('Zero')]
    else:
        words += ' '
     
    if(not len(words) == 0):    
        words += suffixes[index]
        
    return words;
    
def getWords(number):
    length = len(str(number))
    
    if length>12:
        return 'This program supports upto 12 digit numbers.'
    
    count = length // 3 if length % 3 == 0 else length // 3 + 1
    copy = count
    words = []
 
    for i in range(length - 1, -1, -3):
        words.append(process(str(number)[0 if i - 2 < 0 else i - 2 : i + 1], copy - count))
        count -= 1;

    final_words = ''
    for s in reversed(words):
        temp = s + ''
        final_words += temp
    
    return final_words

n = int(input())
if n>10 and n%10==0:
    print(tens[(n//10)-2])
else:
    print(getWords(n))
